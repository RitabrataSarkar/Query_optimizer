import subprocess
import os
import sys

def run_tests():
    # Detect executable based on platform/CMake output
    executable = os.path.join("build", "Debug", "simple_query_optimizer.exe")
    if not os.path.exists(executable):
        executable = os.path.join("build", "simple_query_optimizer.exe")
        if not os.path.exists(executable):
            executable = os.path.join("build", "simple_query_optimizer")

    if not os.path.exists(executable):
        print(f"Error: Executable not found at {executable}. Did you build the project?")
        return False

    with open("examples/sample_queries.sql", "r") as f:
        # Better extraction: remove comments, replace newlines with space, split by semicolon
        lines = f.readlines()
        cleaned_lines = [l for l in lines if not l.strip().startswith("--")]
        text = " ".join([l.strip() for l in cleaned_lines])
        queries = [q.strip() for q in text.split(";") if q.strip()]

    print("Running integration tests...")
    
    # Input commands
    input_data = ";\n".join(queries) + ";\nexit\n"
    
    process = subprocess.run([executable], input=input_data, text=True, capture_output=True)
    
    if process.returncode != 0:
        print(f"Test failed with return code {process.returncode}")
        print(process.stderr)
        return False
        
    output = process.stdout
    if "== Selected Optimized Plan ==" not in output:
        print("Optimization failed to output the expected results.")
        print(output)
        return False
        
    print("Optimization and parsing successfully processed standard queries.")
    return True

if __name__ == "__main__":
    if run_tests():
        sys.exit(0)
    else:
        sys.exit(1)

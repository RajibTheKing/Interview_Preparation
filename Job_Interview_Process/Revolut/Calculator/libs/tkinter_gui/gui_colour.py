import subprocess
import os

def guiForm():
    current_directory = os.path.dirname(os.path.abspath(__file__))
    exe_path = os.path.join(current_directory, 'config.exe')
    subprocess.Popen(exe_path)
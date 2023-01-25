#!/usr/bin/env python3

import subprocess
import os
from tkinter import *
from tkinter import filedialog


root = Tk()
root.withdraw()

my_dir = filedialog.askdirectory(title="Choose the source directory")
dir = filedialog.askdirectory(title="Choose the target directory")

os.chdir(my_dir)
content = subprocess.check_output("ls -a", shell=True).decode().splitlines()

exceptions = [".", "..", ".git", ".gitignore", "deployer.py"]

for file in content:
    if file not in exceptions:
        os.system(f"cp -rf {file} {dir}")  
        print(f"[o] File {file} has been moved.")


print("\n\n[+] Pushing for the remote website...\n")
os.chdir(dir)
os.system(f"git add . && git commit -m \"{input('[*] Commit: ')}\" ; git push")


print("\n\n[+] Pushing for my GitHub...\n")
os.chdir(my_dir)
os.system(f"git add . && git commit -m \"{input('[*] Commit: ')}\" ; git push")
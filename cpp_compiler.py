from tkinter import filedialog
import os


file = filedialog.askopenfilename(title="Select a file")
if file.endswith(".cpp"):
    l=len(file)
    os.system(f'"g++ "{file}" -o "{file[:-4]}.exe"')
else:
    print("[+] Please select a cpp file")

os.system(f'"{file[:-4]}.exe"')
os.system("PAUSE")

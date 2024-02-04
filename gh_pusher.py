import os


os.system("git add .")
os.system(f"git commit -m \"{input('[*] Commit: ')}\"")
os.system("git push")
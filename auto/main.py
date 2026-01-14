import subprocess

def safe_run(command):
    try:
        subprocess.run(command, check=True)
    except subprocess.CalledProcessError as e:
        print(f"Failed to execute command: {command}")
        print(f"Details: {e}")

while True:
    init = input('Do you want to init?(y/n)(default:y): ').lower()
    if init == '' or init == 'y':
        safe_run('git init')
        break
    elif init == "n":
        break
    else:
        print('Answer only with y or n.')

while True:
    push = input('Do you want to push it after every modifire?(y/n)(default:y): ').lower()
    if push == '' or push == 'y':
        push = True
        break
    elif push == "n":
        push = False
        break
    else:
        print('Answer only with y or n.')

def main():
    while True:
        change = input("Whats your changes?: ")
        safe_run('git add .')
        safe_run(f'git commit -m "{change}"')
        if push:
            safe_run('git pull')
            safe_run('git push')
main()

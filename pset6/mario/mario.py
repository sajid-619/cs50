while True:
    try:
        height = int(input("Height: "))
        if (height >= 1) and (height <= 8):
            break
    except:
        print("", end="")

spaces = 1
# prints newline
for i in range(height):

    # prints spaces
    for spaces in range(1, height-i):
        print(" ", end="")

    # prints hashes
    for hashes in range(i+1):
        print("#", end="")

    print()
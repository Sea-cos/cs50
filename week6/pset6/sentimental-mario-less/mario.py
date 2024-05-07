from cs50 import get_int


def print_row(height, bricks):
    for i in range(height - bricks):
        print(" ", end="")
    for i in range(bricks):
        print("#", end="")
    print()


def main():
    n = get_int("Digite uma altura:")
    while n < 1 or n > 8:
        n = get_int("Digite uma altura:")

    for i in range(n):
        print_row(n, i + 1)


if __name__ == "__main__":
    main()

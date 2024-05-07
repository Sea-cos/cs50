from cs50 import get_float


def calc_coins(money, coin_value):
    coins = 0
    while (money >= coin_value):
        coins += 1
        money -= coin_value
    return coins, money


def main():
    valor = get_float("Valor a pagar: ")

    while (valor < 0):
        valor = get_float("Valor a pagar: ")

    cents = round(valor * 100)

    quarters, cents = calc_coins(cents, 25)
    dimes, cents = calc_coins(cents, 10)
    nickels, cents = calc_coins(cents, 5)
    pennies, cents = calc_coins(cents, 1)

    sum = quarters + dimes + nickels + pennies
    print(sum)


if __name__ == "__main__":
    main()

from cs50 import get_float

def main():
    # get input on change owed if >= 0.00
    while True:
        dollars_owed = get_float("Change owed: ")
        cents_owed = round(dollars_owed * 100)
        if cents_owed >= 0.00:
            break

    # Determine respective number of quarters, dimes, nickels, and pennies
    quarters = cents_owed // 25
    dimes = (cents_owed % 25) // 10
    nickels = ((cents_owed % 25) % 10) // 5
    pennies = (((cents_owed % 25) % 10) % 5)

    print(f"{quarters + dimes + nickels + pennies}")

__name__ = "__main__":
    main()
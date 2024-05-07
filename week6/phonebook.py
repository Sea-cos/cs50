people = [
    {"name": "Carter", "number": "12312312"},
    {"name": "David", "number": "23423567"},
    {"name": "John", "number": "97867823"},
]


name = input("Name: ")

for person in people:
    if person["name"] == name:
        number = person["number"]
        print(f"Found {number}")
        break
else:
    print("Not found")


import csv
from sys import argv


def main():

    #Check for command-line usage
    while len(argv) < 3:
        print('Please provide the correct CLA')

    #Read database file into a variable

    with open(argv[1], newline='') as file:
        database = list(csv.reader(file))
        dna_profiles = database[1:]

    #Read DNA sequence file into a variable
    with open(argv[2]) as file:
        dna_seq = file.read()

    #Find longest match of each STR in DNA sequence
    str_matches = [longest_match(dna_seq, seq) for seq in database[0][1:]]

    #Check database for matching profiles
    for profile in dna_profiles:
        if [int(x) for x in profile[1:]] == str_matches:
            print(profile[0])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

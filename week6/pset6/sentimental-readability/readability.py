#Contar letras em uma string
def count_letters(str):
    return len([char for char in str if char.isalpha()])

#Contar frases em uma string
def count_sentences(str):
    sen = 0
    for i in range(len(str)):
        if str[i] == '.' or str[i] == '!' or str[i] == '?':
            sen += 1
    return sen

#Calcular a nota 
def cal_grade(let, wor, sen):
    avg_letters = (let / wor) * 100
    avg_sentences = (sen / wor) * 100

    grade = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8)
    return grade


def main():
    text = input("Digite o texto: ")

    letters = count_letters(text)
    sentences = count_sentences(text)
    words = len(text.split())
    grade = cal_grade(letters, words, sentences)

    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


if __name__ == "__main__":
    main()

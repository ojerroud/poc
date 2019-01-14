import csv


# get the list to define the sentiment

# def get_data(path):
#     list = []

#     fd = open(path, 'r')
#     buff = csv.reader(fd)
#     for row in buff:
#         list.append(row)
#     return (list)


def get_data(path):
    file = open(path, 'r')
    file = file.read()
    return file

def nb_sentences(doc):
    i = 0
    for sent in doc.sents:
        i += 1
    print (i)
    return i

def get_sentences(doc):
    nb = nb_sentences(doc)
    list = [nb]
    for sent in doc.sents:
        i += 1

def sentiment_analyse(doc, list, sentence):
    keke = 0

    for token in doc:
        for i in range(0,len(list)):
            if list[i][0] in token.text:
                keke += int(list[i][1])
    keke = keke / len(sentence.split())
    return keke

# def get_sents():

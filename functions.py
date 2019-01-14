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

def get_sentences(doc):
    list = []
    for sent in doc.sents:
        list.append(sent)

def sentiment_analyse(doc, list, sentence):
    keke = 0

    for token in doc:
        for i in range(0,len(list)):
            if list[i][0] in token.text:
                keke += int(list[i][1])
    keke = keke / len(sentence.split())
    return keke

# def get_sents():

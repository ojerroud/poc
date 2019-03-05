import csv

def sort_n_lower(list):
    list.sort()
    for i in range(0, len(list)):
        list[i][0] = list[i][0].lower()
    return (list)

def get_result_csv(path):
    container = []
    profile = []
    bool = False

    fd = open(path, 'r')
    buff = csv.reader(fd)
    for row in buff:
        if row[0] == "Profil":
            bool = True
            continue
        if bool == False:
            container.append(row)
        else:
            profile.append(row)
    return (container, profile)

def get_keywords(path):
    list = []

    file = open(path, 'r')
    buff = csv.reader(file)
    for row in buff:
        list.append(row)
    sort_n_lower(list)
    return list

def get_sentences(doc):
    list = []
    i = 0
    for sent in doc.sents:
        i += 1
        list.append(sent)
    return (list, i)

def sentiment_analyse(doc, list, sentence):
    keke = 0

    for token in doc:
        for i in range(0,len(list)):
            if list[i][0] in token.text:
                keke += int(list[i][1])
    keke = keke / len(sentence.split())
    return keke

# def get_sents():

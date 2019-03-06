import csv
# import spacy

def print_analyse(analyse):
	for i in range(0, len(analyse)):
		print ('analyse : ',analyse[i])

def get_bad_sentence(result_contenaire, keywords, analyse):
	for i in range(1, len(result_contenaire)):
		for j in range(2, len(result_contenaire[i])):
			bool = False
			for k in range(0, len(keywords)):
				if (result_contenaire[i][j].find(keywords[k][0]) != -1):
					if (len(analyse) == 0):
						analyse.append(result_contenaire[i])
						i += 1
					else:
						for l in range(0, len(analyse)):
							if (analyse[l][3] == result_contenaire[i][3]):
								bool = True
						if (bool == False):
							analyse.append(result_contenaire[i])
							i += 1
	return (analyse)

def put_spacy_on_list(list):
	nlp = spacy.load('fr')
	for i in range(1, len(list)):
		for j in range(2, len(list[i])):
			list[i][j] = nlp(list[i][j])
	return (list)

def sort_n_lower(list):
	for i in range(0, len(list)):
		list[i][0] = list[i][0].lower()
	list.sort()
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
			for i in range(0, len(row)):
				row[i] = row[i].lower()
			container.append(row)
		else:
			for i in range(0, len(row)):
				row[i] = row[i].lower()
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

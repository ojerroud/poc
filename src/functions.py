import csv

def	check_if_negatif(analyse, keywords, negation):
	pos = []
	neg = []

	for i in range(0, len(analyse)):
		for j in range(0, len(analyse[i])):
			for k in range(0, len(keywords)):
				if (analyse[i][j].find(keywords[k][0]) != -1):
					bool = True
					for l in range(0, len(negation)):	
						if (analyse[i][j].find(negation[l][0]) != -1):
							bool = False
							break
					if bool == True:
						pos.append(analyse[i])
					else:
						neg.append(analyse[i])
	return pos, neg

def print_analyse(analyse, head):
	for i in range(0, len(analyse)):
		print (head, end="")
		print (analyse[i])

def get_bad_sentence(result_contenaire, keywords):
	analyse = []

	for i in range(1, len(result_contenaire)):
		for j in range(2, len(result_contenaire[i])):
			bool = False
			for k in range(0, len(keywords)):
				if (result_contenaire[i][j].find(keywords[k][0]) != -1):
					if (len(analyse) == 0):
						analyse.append(result_contenaire[i])
						break
					else:
						for l in range(0, len(analyse)):
							if (analyse[l][3] == result_contenaire[i][3]):
								bool = True
						if (bool == False):
							analyse.append(result_contenaire[i])
							break
	return analyse

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
	return container, profile

def	space_on_list_if_negation(list, path, i):
	if (path.find("negation") != -1):
		if (list[i][0][len(list[i][0]) - 1] != "'"):
			list[i][0] = " "+list[i][0].lower()+" "
		else:
			list[i][0] = " "+list[i][0].lower()

def sort_n_lower(list, path):
	for i in range(0, len(list)):
		list[i][0] = list[i][0].lower()
		space_on_list_if_negation(list, path, i)
	list.sort()
	return list

def get_keywords(path):
	keywords = []

	file = open(path, 'r')
	buff = csv.reader(file)
	for row in buff:
		keywords.append(row)
	sort_n_lower(keywords, path)
	return keywords

# when spacy will be implemented

def put_spacy_on_list(list):
	nlp = spacy.load('fr')
	for i in range(1, len(list)):
		for j in range(2, len(list[i])):
			list[i][j] = nlp(list[i][j])
	return list

def get_sentences(doc):
	list = []
	i = 0
	for sent in doc.sents:
		i += 1
		list.append(sent)
	return list, i

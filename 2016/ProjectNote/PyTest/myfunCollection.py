#update noun list
import MyUtility
def myfun_3(lowerRange,upperRange):
	global cursor,kl,items;
	for i in range(lowerRange,upperRange):
		if(kl[i].decode('utf-8')==MyUtility.TakeWordRemoveDot(items[i][1]) and MyUtility.FindNoun(items[i][1])):
			st1=MyUtility.FindGender(items[i][1]);
			if(st1!=''):
				genetivform='';
				pluralform='';
				[genetivform,pluralform]=MyUtility.FindPluralAndGenetiv(items[i][1],st1);
				cursor.execute(u"update Noun set plural='{0}',genitiv='{1}' where wordform='{2}'".format(pluralform,genetivform,kl[i].decode('utf-8')));


#insert new noun to noun list
def myfun_4(starting,ending):
	for i in range(starting,ending):
		if(kl[i].decode('utf-8')==MyUtility.TakeWordRemoveDot(items[i][1]) and MyUtility.FindNoun(items[i][1])):
			st1=MyUtility.FindGender(items[i][1]);
			if(st1!=''):
				genitivform='';
				pluralform='';
				[genitivform,pluralform]=MyUtility.FindPluralAndGenetiv(items[i][1],st1);
				cursor.execute(u"insert into Noun(wordform,gender,genitiv,plural) values('{0}','{1}','{2}','{3}')".format(kl[i].decode('utf-8'),st1,genitivform,pluralform));

#delete entry from noun list
def myfun_2(lowerRange,upperRange):
	global cursor;
	for i in range(lowerRange,upperRange):
		cursor.execute("delete from Noun where ID={0}".format(i));

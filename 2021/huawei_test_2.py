num = int(input())
dic = {}
dic_instance = {}
for i in range(num):
    st = input()
    if st.find('subClassOf') > 0:
        st = st.rstrip(' ')
        a, _, b = st.split(' ')
        if dic.get(b) is None:
            dic[b] = []
        dic[b].append(a)
    else: # instance of
        a, _, b = st.split(' ')
        if dic_instance.get(b) is None:
            dic_instance[b] = []
        dic_instance[b].append(a)
query = input()
# find all concepts
concept_list = [query]
query_list = [query]

while len(query_list) > 0:
    current_query = query_list.pop()
    if dic.get(current_query):
        concept_list.extend(dic[current_query])
        query_list.extend(dic[current_query])

instance_list = []
for concept in concept_list:
    if dic_instance.get(concept):
        instance_list.extend(dic_instance[concept])
instance_list.sort()
#import pdb
#pdb.set_trace()
if len(instance_list) == 0:
    print('empty')
else:
    print(' '.join(instance_list))

import numpy as np
import networkx as nx
import matplotlib.pyplot as plt

er = nx.generators.random_graphs.erdos_renyi_graph(200, 0.05)
nx.drawing.nx_pylab.draw_networkx(er, pos=nx.spring_layout(er), node_size=100, with_labels=False, seed=1)
# first figure, sbm graph
plt.savefig('build/er1.svg')
plt.clf()

node_color_list = ['red' for i in range(100)]
node_color_list.extend(['blue' for i in range(100)])
nx.drawing.nx_pylab.draw_networkx(er, pos=nx.spring_layout(er), node_size=100, with_labels=False, node_color=node_color_list, seed=1)
# second figure, sbm graph with two kinds of color
plt.savefig('build/er2.svg')
plt.clf()


# assign weights
p = 0.09
q = 0.01
iw = 3 # inner weight
sbm = nx.generators.community.stochastic_block_model([100, 100], np.array([[p,q],[q,p]]))

for u, v in sbm.edges:
    if sbm.nodes[u]['block'] == sbm.nodes[v]['block']:
        sbm[u][v]['weight'] = iw
    else:
        sbm[u][v]['weight'] = 1
nx.drawing.nx_pylab.draw_networkx(sbm, pos=nx.spring_layout(sbm), node_size=100, with_labels=False, node_color=node_color_list)
plt.savefig('build/sbm3.svg')

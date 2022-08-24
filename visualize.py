import networkx as nx
import matplotlib.pyplot as plt
g = nx.Graph()
lines = []
with open('graph_sparse0.txt') as f:
    lines = f.readlines()
i=0
for line in lines:
    data=line.split(',')
    for j in range(0,len(data)-1,2):
        g.add_edge(int(i), int(data[j]),weight=int(data[j+1]))
    i=i+1
g2 = g.to_undirected()
print(len(list(g2.edges)))
#print(g2.degree[0])

pos=nx.spring_layout(g2) # pos = nx.nx_agraph.graphviz_layout(G)
nx.draw_networkx(g2,pos)
labels = nx.get_edge_attributes(g2,'weight')
nx.draw_networkx_edge_labels(g2,pos,edge_labels=labels)
plt.savefig("filename.png")

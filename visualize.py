import networkx as nx
import matplotlib.pyplot as plt
g = nx.Graph()
lines = []
with open('graph1.txt') as f:
    lines = f.readlines()
i=0
for line in lines:
    data=line.split(',')
    for j in range(0,len(data)-1,2):
        g.add_edge(int(i), int(data[j]),weight=int(data[j+1]))
        #j=j+1
    i=i+1
    print(i)
    #print(data)

pos=nx.spring_layout(g) # pos = nx.nx_agraph.graphviz_layout(G)
nx.draw_networkx(g,pos)
labels = nx.get_edge_attributes(g,'weight')
nx.draw_networkx_edge_labels(g,pos,edge_labels=labels)
plt.savefig("filename.png")

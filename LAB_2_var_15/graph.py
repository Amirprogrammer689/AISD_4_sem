import matplotlib.pyplot as plt

table_sizes = [25, 75, 125, 175, 225, 275, 325, 375, 425, 475]
collisions = [1975, 1925, 1875, 1825, 1775, 1725, 1675, 1626, 1579, 1530]

plt.figure(figsize=(10, 6))
plt.plot(table_sizes, collisions, marker='o', color='b', linestyle='-', linewidth=2)

plt.title('Зависимость количества коллизий от размера хеш-таблицы')
plt.xlabel('Размер таблицы')
plt.ylabel('Количество коллизий')
plt.grid(True)
plt.xticks(table_sizes)

plt.show()
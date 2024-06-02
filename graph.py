import matplotlib.pyplot as plt

# Чтение данных из файла
dispersion = []
ber = []

with open('ber_data.txt', 'r') as file:
    for line in file:
        d, b = map(float, line.split())
        dispersion.append(d)
        ber.append(b)

# Построение графика
plt.figure(figsize=(10, 6))
plt.plot(dispersion, ber, marker='o')
plt.title('BER vs Noise Dispersion')
plt.xlabel('Noise Dispersion')
plt.ylabel('Bit Error Rate (BER)')
plt.grid(True)
plt.show()

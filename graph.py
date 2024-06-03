import matplotlib.pyplot as plt

# Чтение данных из файла
dispersion = []
ber = []
ber16 = []
ber64 = []


with open('ber_data.txt', 'r') as file:
    for line in file:
        d, b = map(float, line.split())
        dispersion.append(d)
        ber.append(b)
        
with open('ber_data_16.txt', 'r') as file:
    for line in file:
        d, b = map(float, line.split())
        ber16.append(b)

with open('ber_data_64.txt', 'r') as file:
    for line in file:
        d, b = map(float, line.split())
        ber64.append(b)

# Построение графика
plt.figure(figsize=(10, 6))
plt.plot(dispersion, ber, marker='o')
plt.title('BER vs Noise Dispersion')
plt.xlabel('Noise Dispersion')
plt.ylabel('Bit Error Rate (BER)')
plt.grid(True)
plt.show()

plt.figure(figsize=(10, 6))
plt.plot(dispersion, ber16, marker='o')
plt.title('BER16 vs Noise Dispersion')
plt.xlabel('Noise Dispersion')
plt.ylabel('Bit Error Rate (BER16)')
plt.grid(True)
plt.show()

plt.figure(figsize=(10, 6))
plt.plot(dispersion, ber64, marker='o')
plt.title('BER64 vs Noise Dispersion')
plt.xlabel('Noise Dispersion')
plt.ylabel('Bit Error Rate (BER64)')
plt.grid(True)
plt.show()
import serial

conexao = serial.Serial('COM5',9600)

while True:
    try:
        valorUltrassonico = conexao.readline().decode('utf-8').strip()
        
        distancia = int(valorUltrassonico)
        
        print("Distância em cm: ", distancia)
        
        if distancia < 10:
            conexao.write(b'R')
        elif distancia >= 10 and distancia <= 50:
            conexao.write(b'A')
        elif distancia > 50:
            conexao.write(b'V')
            
    except KeyboardInterrupt:
        print("Programa encerrado.")
        break

conexao.close()
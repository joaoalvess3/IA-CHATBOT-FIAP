# IA-CHATBOT-FIAP

# 2-TDSG
# JOÃO ARMANDO
# JOÃO PEDRO NARDI


#https://arnaldojr.github.io/IoT/aulas/lab6/ (EXERCICIO)

Desenvolvemos um protótipo de um sistema de identificação IOT.

Na primeira parte do projeto o nosso sistema foi capaz de coletar e identificar o "TAG FRID" fazendo a ligação com o arduino, enviando informações em formato .JSON para o fluxo no nod-red, onde o mesmo realiza 2 funções, publicar um tópico utilizando o protocolo MQTT.

Há também um segundo fluxo do nod-red que subscreve o tópico que exibe o valor da TAG em um dashboard.


O projeto foi feito utilizando as seguintes ferramentas:
- IDE Arduino;
- Nod-Red;
- JSON;

Biblioteca usanda para o desenvolvimento do projeto: 
- MFRC522;
- Arduino Json;

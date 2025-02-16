# 📡 Monitoramento de Temperatura e Umidade com Arduino e Node-RED

Este projeto implementa um sistema de **monitoramento de temperatura e umidade** utilizando um **sensor DHT11**, um **Arduino**, e um **dashboard no Node-RED** para visualização dos dados em tempo real.

## 🚀 Tecnologias Utilizadas
- **Arduino UNO** (ou compatível)
- **Sensor DHT11**
- **Node-RED**
- **ArduinoJson (para formatação dos dados)**
- **Node-RED Dashboard (para visualização gráfica)**
- **Comunicação Serial (USB)**

---

## 🛠 Instalação e Configuração

### 🔹 1. Configuração do Arduino

#### 📌 Instalação de Bibliotecas no Arduino IDE
Antes de carregar o código no Arduino, é necessário instalar as seguintes bibliotecas:

- **DHT Sensor Library** (para leitura do DHT11)
- **ArduinoJson** (para formatação dos dados em JSON)

📌 **Passos para instalação das bibliotecas**:
1. Abra a **Arduino IDE**.
2. Vá até **Ferramentas** → **Gerenciar Bibliotecas**.
3. Pesquise por `"DHT Sensor Library"` e instale a versão mais recente.
4. Pesquise por `"ArduinoJson"` e instale a versão mais recente.

Após instalar as bibliotecas, carregue o código-fonte do Arduino no microcontrolador.

---

### 🔹 2. Instalação e Configuração do Node-RED

#### 📌 Instalação do Node-RED

Caso o Node-RED ainda não esteja instalado, siga os passos abaixo:

**Windows**
1. Instale o **Node.js** a partir de: [https://nodejs.org/](https://nodejs.org/)
2. No **Prompt de Comando (cmd)**, execute:
npm install -g --unsafe-perm node-red

3. Inicie o Node-RED com:
node-red

4. Acesse o Node-RED no navegador:  
**http://localhost:1880**


---

### 🔹 4. Configuração dos Nodes no Node-RED

Para processar e exibir os dados recebidos via **Serial**, crie o seguinte fluxo no Node-RED.

#### 📌 Nodes necessários no fluxo:
1. **"Serial in"** → Lê os dados da Serial do Arduino.  
2. **"json"** → Converte a string JSON do Arduino para um objeto JSON.  
3. **"debug"** → Exibe os dados para depuração.  
4. **"gauge"** → Exibe a temperatura no dashboard.  
5. **"gauge"** → Exibe a umidade no dashboard.  

---

### 🔹 5. Configuração do Nó "Serial in"

1. Arraste o nó **"Serial in"** para o fluxo.
2. **Clique duas vezes** e configure:
   - **Porta Serial**: Escolha a porta do Arduino (`COM3`, `COM4`, etc.).
   - **Baud Rate**: `9600`
   - **Formato de Dados**: `string`
3. Clique em **Done** e conecte o nó ao próximo nó no fluxo.

---

### 🔹 6. Configuração do Nó "Gauge" para Temperatura

1. Arraste um **nó "gauge"** para o fluxo.
2. Clique duas vezes e configure:
   - **Group**: `"Sensores"` (criar novo grupo se necessário).
   - **Label**: `"Temperatura"`.
   - **Value Format**: `{{msg.payload.temperatura}}`.
   - **Units**: `"°C"`.
   - **Range Min/Max**: `0 a 50`.
3. Clique em **Done**.

📌 **Para exibir a umidade, crie outro gauge e use:**  
`{{msg.payload.umidade}}`

---

### 🔹 7. Deploy e Acesso ao Dashboard

1. Clique em **Deploy** no Node-RED.
2. Acesse o **dashboard** no navegador:  
   **http://localhost:1880/ui**
3. Agora, os dados da **temperatura e umidade do sensor DHT11** aparecerão no painel!

---

## 🎯 Resumo Final

| **Etapa** | **Ação** |
|-----------|---------|
| **Arduino** | Instalamos as bibliotecas **DHT Sensor** e **ArduinoJson** |
| **Código** | Criamos um código para ler o DHT11 e enviar dados JSON via **Serial** |
| **Node-RED** | Instalamos o Node-RED e os módulos **node-red-node-serialport** e **node-red-dashboard** |
| **Nodes Criados** | **Serial in**, **json**, **debug**, **gauge** (temperatura e umidade) |
| **Dashboard** | Criamos um **dashboard** acessível via `http://localhost:1880/ui` |

---

## 🚀 Próximos Passos

Agora que o sistema está funcionando localmente, podemos:
- **Enviar os dados via MQTT** para permitir acesso remoto.
- **Armazenar os dados em uma base de dados** como Firebase ou InfluxDB.
- **Criar alertas para valores críticos** usando notificações.

Caso tenha dúvidas ou melhorias, fique à vontade para contribuir! 🚀🔥

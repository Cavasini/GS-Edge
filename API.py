from flask import Flask, jsonify
import json

app = Flask(__name__)

# Carregar dados do arquivo JSON
with open('mqtt_data.json', 'r') as file:
    data = json.load(file)

# Definir rota para "/TEF/Vita300/attrs/validade"
@app.route('/validade', methods=['GET'])
def get_validade():
    return jsonify({'validade': data["/TEF/Vita300/attrs/validade"]})

# Definir rota para "/TEF/Vita300/attrs/estoque"
@app.route('/estoque', methods=['GET'])
def get_estoque():
    return jsonify({'estoque': data["/TEF/Vita300/attrs/estoque"]})

# Definir rota para "/TEF/Vita300/attrs/user"
@app.route('/user', methods=['GET'])
def get_user():
    return jsonify({'user': data["/TEF/Vita300/attrs/user"]})

if __name__ == '__main__':
    app.run(debug=True)

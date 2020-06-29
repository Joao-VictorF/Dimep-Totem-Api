### Instalando depedências e iniciando o servidor:

```sh
$ wget -qO- http://bit.ly/ngrest | bash
$ cd api/
$ ngrest
```

### Preparações necessárias em arquivos para colocar o projeto em produção:
- arquivo settings.json na raiz com os objetos de configuração do totem vazios

- arquivo user.json na pasta login/src com os seguintes objetos (padrão)
```
{
    "firstAccess": true, //Para informar que o usuário deve mudar as credenciais após o 1o login
    "password": "admin", // username padrão
    "username": "admin"  // password padrão
}
```

- arquivo token.json na pasta login/src com o seguinte objeto (padrão)
```
{
    "token": "", //Para armazenar os tokens depois do login
}
```

### Deploy com Apache Server
https://github.com/loentar/ngrest/wiki/Deploy-ngrest-under-Apache2-Web-Server

### Deploy com Nginx
https://github.com/loentar/ngrest/wiki/Deploy-ngrest-under-Nginx


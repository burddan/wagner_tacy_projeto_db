#/bin/zsh
read -sp "digite a senha super secreta do postgres da vps: " senha
echo
./main postgres "$senha" database 23.95.209.246

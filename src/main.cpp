#include "WiFi.h"

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Iniciando WiFi...");
  WiFi.mode(WIFI_STA);
  Serial.println("Configuração concluída!");
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.println("Procurando...");

  int qtdeRedes = WiFi.scanNetworks();
  Serial.println("Verificação concluída.");

  if (qtdeRedes == 0)
  {
    Serial.println("Nenhuma rede encontrada.");
  }
  else
  {
    Serial.print("Total de rede(s) encontrada(s): ");
    Serial.println(qtdeRedes);

    for (int i = 0; i < qtdeRedes; i++)
    {
      Serial.print(i + 1);
      Serial.print(": ");

      Serial.print(WiFi.SSID(i)); // nome da rede encontrada
      Serial.print(" - Sinal (");

      Serial.print(WiFi.RSSI(i)); // intensidade do sinal
      Serial.print(") - Possui senha? ");

      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "Não" : "Sim");
      delay(10);
    }
    delay(5000);
  }
}
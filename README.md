Primjeri signala :
  1. SIGINT: Prekida proces, često zbog greške, npr. pomoću CTRL + C
  2. SIGTERM: Zahtijeva uredno gašenje procesa
(https://www.geeksforgeeks.org/signals-c-language/)


#INSTALACIJA
  1. Klonirajte ovaj repozitorij na vaše računalo. "git clone <URL_repozitorija>
  2. cd <ime_repozitorija>

#KORIŠTENJE
  1. Kompajlirajte program nakon sto ste se pozicionirali u repozitorij : "gcc signali.c -o signal_program"
  2. Pokrenite program u jednom terminalu : "./signal_program
  3. U drugom terminalu, pošaljite signale procesu koristeći "kill" naredbu:
     - za slanje signala SIGINT -> kill -SIGINT <PID>
     - za slanje signala SIGTERM -> kill -SIGTERM <PID>
     - za slanje signala SIGUSR1 -> kill -SIGUSR1 <PID>
     - za slanje signala SIGUSR2 -> kill -SIGUSR2 <PID>

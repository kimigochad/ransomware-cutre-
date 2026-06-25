### ransomware-cutre-
# ransomware cutre y simple, programado en c en menos de 50 lineas de codigo

este ransomware fue hecho estando orientado en el entendimiento de este tipo de malware.
es simple y no se compara en lo sofisticado que son los ransomware hoy en dia, fue hecho para dar una idea(ejemplo) de como funciona este tipo de malware.
Porfavor si utilizas este ejemplo con intensiones malevolas, no me heches la culpa porque fue hecho para dar educacion de este tipo de malware, se un poco hombre y se responsable.
incripta todo en chacha20, tiene la misma key y nonce en cada encriptación, funcionando como desincriptador al mismo tiempo

simple diagrama del tipo de cifrado(chacha20):
   ┌───────────────┐
   │   Texto plano │
   └───────┬───────┘
           │
           ▼
   ┌───────────────────────┐
   │ ChaCha20 (clave+nonce)│
   └───────┬───────────────┘
           │
           ▼
   ┌───────────────┐
   │ Texto cifrado │
   └───────┬───────┘
           │
           ▼
   ┌───────────────────────┐
   │ ChaCha20 (misma clave │
   │       + mismo nonce)  │
   └───────┬───────────────┘
           │
           ▼
   ┌───────────────┐
   │   Texto plano │
   └───────────────┘

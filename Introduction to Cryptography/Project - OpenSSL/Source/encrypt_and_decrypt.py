import key_generation
from cryptography.hazmat.primitives.asymmetric.padding import PKCS1v15

def encrypt(message):
    """
    Encrypt message
    """
    pub_key, _ = key_generation.get_pub_key()

    encrypted = pub_key.encrypt(message.encode(), PKCS1v15())

    return encrypted

def decrypt(encrypted):
    """
    Decrypt message
    """
    priv_key, _ = key_generation.get_priv_key()
    encrypted = encrypted

    decrypted = priv_key.decrypt(encrypted, PKCS1v15()).decode()

    return decrypted

def export_encrypted_message(encrypted):
    try:
        with open("code_outputs/encrypted_message.txt", "wb") as encrypted_file:
            encrypted_file.write(encrypted)
        return True
    except:
        return False
    

if __name__ == "__main__":
    # Encrypt message
    print("\n---ENCRYPTED MESSAGE---")
    encrypted = encrypt(key_generation.get_message())
    print(int.from_bytes(encrypted, byteorder="big"))

    # Decrypt message
    print("\n---DECRYPTED MESSAGE---")
    decrypted = decrypt(encrypted)
    print(decrypted)

    # Export encrypted message
    print("\n---EXPORT ENCRYPTED MESSAGE---")
    exported = export_encrypted_message(encrypted)
    print("Encrypted Message Exported Successfully" if exported else "Encrypted Message Exported Failed")
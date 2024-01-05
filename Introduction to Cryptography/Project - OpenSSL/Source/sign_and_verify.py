import key_generation
from cryptography.hazmat.primitives.asymmetric.padding import PKCS1v15
from cryptography.hazmat.primitives.hashes import SHA256

def sign(message):
    """
    Sign message
    """
    priv_key, _ = key_generation.get_priv_key()

    signature = priv_key.sign(
        message.encode(),
        PKCS1v15(),
        SHA256()
    )

    return signature

def verify(signature):
    """
    Verify signature
    """
    pub_key, _ = key_generation.get_pub_key()
    signature = signature

    try:
        pub_key.verify(
            signature,
            key_generation.get_message().encode(),
            PKCS1v15(),
            SHA256()
        )
        return True
    except:
        return False
    
def export_signature(signature):
    try:
        with open("code_outputs/signature.txt", "wb") as signature_file:
            signature_file.write(signature)
        return True
    except:
        return False
    
if __name__ == "__main__":
    print("\n---SIGNATURE---")
    signature = sign(key_generation.get_message())
    print(int.from_bytes(signature, byteorder="big"))

    print("\n---VERIFY---")
    verified = verify(signature)
    print("Signature Verified Successfully" if verified else "Signature Verified Failed")

    print("\n---EXPORT SIGNATURE---")
    exported = export_signature(signature)
    print("Signature Exported Successfully" if exported else "Signature Exported Failed")
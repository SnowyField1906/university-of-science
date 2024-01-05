from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.backends import default_backend

PRIV_KEY = "openssl_outputs/priv.pem"
PUB_KEY = "openssl_outputs/pub.pem"
MESSAGE = "openssl_outputs/message.txt"

def get_priv_key():
    """
    Decode private key from file
    """
    with open(PRIV_KEY, "rb") as key_file:
        key = serialization.load_pem_private_key(
            key_file.read(),
            password=None,
            backend=default_backend()
        )
    
    pub = key.public_key().public_numbers()
    priv = key.private_numbers()
    
    return (key, {
        "n": pub.n,
        "e": pub.e,
        "d": priv.d,
        "p": priv.p,
        "q": priv.q,
        "dmp1": priv.dmp1,
        "dmq1": priv.dmq1,
        "iqmp": priv.iqmp
    })
    
def get_pub_key():
    """
    Decode public key from file
    """
    with open(PUB_KEY, "rb") as key_file:
        key = serialization.load_pem_public_key(
            key_file.read(),
            backend=default_backend()
        )
    
    pub = key.public_numbers()
    
    return (key, {
        "n": pub.n,
        "e": pub.e
    })

def get_message():
    """
    Read plain message from file
    """
    with open(MESSAGE) as message_file:
        message = message_file.read()
        return message

    
if __name__ == "__main__":
    print("---MESSAGE---")
    message = get_message()
    print(message)

    print("\n---PRIVATE KEY---")
    _, priv_key = get_priv_key()
    print("n:", priv_key["n"])
    print("e:", priv_key["e"])
    print("d:", priv_key["d"])
    print("p:", priv_key["p"])
    print("q:", priv_key["q"])
    print("dmp1:", priv_key["dmp1"])
    print("dmq1:", priv_key["dmq1"])
    print("iqmp:", priv_key["iqmp"])

    print("\n---PUBLIC KEY---")
    _, pub_key = get_pub_key()
    print("n:", pub_key["n"])
    print("e:", pub_key["e"])
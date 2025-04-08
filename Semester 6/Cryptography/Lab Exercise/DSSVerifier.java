import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.Signature;
import java.util.Base64;

public class DSSVerifier {
    public static void main(String[] args) {
        try {
            KeyPairGenerator keyGen = KeyPairGenerator.getInstance("DSA");
            keyGen.initialize(2048);
            KeyPair keyPair = keyGen.generateKeyPair();
            
            System.out.println("Key Pair Details");
            System.out.println("Private Key (Base64): \n" + 
                Base64.getEncoder().encodeToString(keyPair.getPrivate().getEncoded()));
            System.out.println("\nPublic Key (Base64): \n" + 
                Base64.getEncoder().encodeToString(keyPair.getPublic().getEncoded()));
            
            String legalDocument = "This is a legally binding agreement between Party A and Party B...";
            byte[] documentBytes = legalDocument.getBytes();
            
            byte[] signature = signDocument(documentBytes, keyPair.getPrivate());
            System.out.println("\nDigital Signature Details");
            System.out.println("Generated Signature (Base64): \n" + 
                Base64.getEncoder().encodeToString(signature));
            System.out.println("Signature Length: " + signature.length + " bytes");
            
            System.out.println("\nVerification Process");
            System.out.println("Using Public Key: " + 
                keyPair.getPublic().getAlgorithm() + " " + 
                keyPair.getPublic().getFormat());
            
            boolean verified = verifySignature(documentBytes, signature, keyPair.getPublic());
            
            System.out.println("\nVerification Result");
            if (verified) {
                System.out.println("Legal communication verified successfully");
            } else {
                System.out.println("Verification failed");
            }
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public static byte[] signDocument(byte[] document, PrivateKey privateKey) throws Exception {
        Signature dsa = Signature.getInstance("SHA256withDSA");
        dsa.initSign(privateKey);
        dsa.update(document);
        return dsa.sign();
    }
    
    public static boolean verifySignature(byte[] document, byte[] signature, PublicKey publicKey) throws Exception {
        Signature verifier = Signature.getInstance("SHA256withDSA");
        verifier.initVerify(publicKey);
        verifier.update(document);
        return verifier.verify(signature);
    }
}

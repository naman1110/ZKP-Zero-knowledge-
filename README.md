# Zero-Knowledge Proofs

# Overview

Zero-knowledge proofs allow one party (the prover) to convince another party (the verifier) that they know certain information, without revealing the information itself.
This is done through an interactive protocol where the prover answers challenges from the verifier in a way that demonstrates knowledge of the secret information.
Zero-knowledge proofs have important applications in cryptography and privacy-preserving systems.
# Example Scenario

Alice knows the password to open a lock. Bob wants to ensure Alice knows the password without her revealing it.
Alice can prove she knows the password by answering challenges from Bob.
Bob issues random challenges - he asks Alice to either open the lock or do nothing.
If Alice is able to open the lock when challenged, or do nothing when not challenged, this convinces Bob she knows the password without revealing it.
# Example Code

Secret password is stored in constant string secret_password
Prover class initialized with password, implements logic to respond to challenges
Verifier class generates random challenges and verifies responses
# Main loop:
Verifier issues random challenge
Prover generates response
Verifier checks if response matches expected
After multiple iterations, Verifier is convinced of Prover's knowledge without password being revealed
Key Properties Demonstrated

Completeness - an honest prover who knows the secret can convince the verifier
Soundness - a dishonest prover cannot convince the verifier without knowing the secret
Zero-knowledge - the verifier learns nothing about the secret from the interaction

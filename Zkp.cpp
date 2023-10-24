#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


const std::string secret_password = "password";

// Prover 
class Prover {
public:
    Prover(const std::string& secret) : secret_(secret) {}

    std::string respond(const std::string& challenge) {
        if (challenge == "Open the door") {
            return secret_;
        } else {
            return "No response"; // Simulate not revealing the secret
        }
    }

private:
    const std::string& secret_;
};

// Verifier 
class Verifier {
public:
    std::string challenge() {
        int random = rand() % 2;
        return (random == 0) ? "Open the door" : "Remain silent";
    }

    bool verify(const std::string& response, const std::string& challenge) {
        if (challenge == "Open the door" && response == secret_password) {
            return true;
        } else if (challenge == "Remain silent" && response == "No response") {
            return true;
        }
        return false;
    }
};

int main() {
 

    Prover prover(secret_password);
    Verifier verifier;

    for (int i = 0; i < 5; i++) {  // Perform 5 iterations
        std::string challenge = verifier.challenge();
        std::string response = prover.respond(challenge);

        if (verifier.verify(response, challenge)) {
            std::cout << "Challenge: " << challenge << " - Verified" << std::endl;
        } else {
            std::cout << "Challenge: " << challenge << " - Failed" << std::endl;
        }
    }

    return 0;
}

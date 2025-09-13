FROM gcc:15.2.0


RUN apt-get update && apt-get install -y libssl-dev bear


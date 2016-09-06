mkdir amandus
cd amandus
git clone https://bitbucket.org/guidokanschat/amandus.git
mkdir build
cd build
cmake -DDEAL_II_DIR=$HOME/deal.II/installed ../amandus
make

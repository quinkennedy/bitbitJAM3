sudo apt-get update
# If `make build-dep` hangs installing g++
# you can try installing g++ separately first.
# but it doesn't seem to be necessary all the time.
#sudo apt-get install -y g++
cd /vagrant/gbdk
sudo make build-dep
sudo make install

sudo ln -s /opt/gbdk/bin/lcc /usr/local/bin/lcc

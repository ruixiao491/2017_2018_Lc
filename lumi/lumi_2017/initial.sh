export PATH=$HOME/.local/bin:/cvmfs/cms-bril.cern.ch/brilconda/bin:$PATH
pip uninstall brilws
pip install --install-option="--prefix=$HOME/.local" brilws

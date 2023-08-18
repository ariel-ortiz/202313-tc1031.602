#pragma once

const int total_dinos = 8;

enum class DinoId {
    velociraptor,        // 0
    stegosaurus,         // 1
    tyrannosaurus,       // 2
    procompsognathus,    // 3
    triceratops,         // 4
    pachycephalosaurus,  // 5
    parasaurolophus,     // 6
    pteranodon           // 7
};

class DinoSet {

public:

    void add(DinoId id)
    {
        int index = static_cast<int>(id);
        _dino[index] = true;
    }

    bool contains(DinoId id) const
    {
        int index = static_cast<int>(id);
        return _dino[index];
    }

    DinoSet operator+(const DinoSet& other) const
    {
        DinoSet result;
        for (int i = 0; i < total_dinos; ++i) {
            DinoId id = static_cast<DinoId>(i);
            if (contains(id) or other.contains(id)) {
                result.add(id);
            }
        }
        return result;
    }

    std::string to_string() const
    {
        std::string result = "";
        for (int i = 0; i < total_dinos; ++i) {
            if (_dino[i]) {
                result += "1";
            } else {
                result += "0";
            }
        }
        return result;
    }

private:

    bool _dino[total_dinos] {};
};

#pragma once

#include <iostream>
#include <vector>

#include "../imageData/imageData.h"
#include "../../const.h"





class ImagesData
{
public:
    std::vector<ImageData> imagesData;



    int imageNumber;

    ImagesData() : imageNumber(0) {}

    // Constructeur de copie
    ImagesData(const ImagesData& other)
        : imagesData(other.imagesData), imageNumber(other.imageNumber) {}

    ImagesData(const std::vector<ImageData> a) : imagesData(a) {}

    ImagesData& operator=(const ImagesData& other);

    //  Définit le numéro de l'image actuel dans imagesData 
    void setImageNumber(int nbr);

    //  Renvoie le numéro de l'image actuel dans imagesData 
    int getImageNumber();

    // Affiche imagesData
    void print() const;

    // Permet d'ajouter une ImageData à imagesData
    void addImage(ImageData& imageD);

    // Permet d'enlever une ImageData à imagesData
    void removeImage(const ImageData& image);

    // Permet de recuperer la MetaData de l'ImageData à l'id
    ImageData* getImageData(int id);

    // Permet de recuperer la MetaData de l'ImageData actuellement utilisé
    ImageData* getCurrentImageData();

    // Permet de recuperer imagesData
    std::vector<ImageData>& get();


    // Permet de sauvegarder ImagesData à partir d'un fichier binaire
    void saveImagesData(std::string savePath);

    // Sauvegarder ImageData entier en binaire
    void save(std::ofstream& out) const;

    // Charger ImageData à partir d'un fichier binaire
    void load(std::ifstream& in);

};

// Permet de charger ImagesData à partir d'un fichier binaire
ImagesData loadImagesData(std::string savePath);

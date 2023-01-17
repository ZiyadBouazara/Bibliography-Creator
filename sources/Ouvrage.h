/*
 * \file Ouvrage.h
 * \brief initialisation de la classe Ouvrage
 * \author Emilio Lemus
 * \date 2022-11-28
 *
 */

#ifndef OUVRAGE_H
#define OUVRAGE_H

#include <string>
#include "Reference.h"
#include "ContratException.h"

/*
 * \namespace biblio
 * \brief namespace pour la construction de bibliographie
 */

namespace biblio
{

  class Ouvrage : public biblio::Reference
  {
  public: // le parametre p_annee a revoir dans le constructeur car const unsigned int :|
    Ouvrage (const std::string& p_auteurs, const std::string& p_titre,
             const unsigned int& p_annee, const std::string& p_identifiant,
             const std::string& p_editeur, const std::string& p_ville);

    const std::string reqEditeur () const;
    const std::string reqVille () const;
    virtual const std::string reqReferenceFormate () const;
    virtual Reference* clone () const;

  private:
    void verifieInvariant () const; // this has not yet been implemented
    std::string m_editeur; // editeur de l'ouvrage
    std::string m_ville; // ville d'edition de l'ouvrage

  };
} // namespace biblio

#endif /* OUVRAGE_H */


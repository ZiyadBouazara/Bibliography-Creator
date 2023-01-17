/*
 * \file Reference.h
 * \brief initialisation de la classe Reference
 * \author Emilio Lemus
 * \date 2022-11-28
 *
 */

#ifndef REFERENCE_H
#define REFERENCE_H

#include "ContratException.h"

/*
 * \namespace biblio
 * \brief namespace pour la construction de bibliographie
 */

namespace biblio
{

  class Reference
  {
  public:
    Reference (const std::string& p_auteurs, const std::string& p_titre,
               const unsigned int& p_annee, const std::string& p_identifiant);

    virtual
    ~Reference () { };

    bool operator== (const Reference& p_reference) const;

    const std::string & reqAuteurs () const;
    const std::string & reqTitre () const;
    const unsigned int& reqAnnee () const;
    const std::string & reqIdentifiant () const;

    void asgAnnee (const unsigned int& p_annee);

    virtual const std::string reqReferenceFormate () const;
    virtual Reference* clone () const = 0;

  private:
    void verifieInvariant () const;

    std::string m_auteurs; // Auteur(s) de la ref
    std::string m_titre; // Titre de la ref
    unsigned int m_annee; // Annee d'édition de la ref
    std::string m_identifiant; // Identifian ISBN ou ISSN de la ref

  };
} // namespace biblio



#endif /* REFERENCE_H */


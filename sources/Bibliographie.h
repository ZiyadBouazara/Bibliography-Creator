/*
 * \file Bibliographie.h
 * \brief initialisation de la classe Bibliographie
 * \author Emilio Lemus
 * \date 2022-11-28
 *
 */

#ifndef BIBLIOGRAPHIE_H
#define BIBLIOGRAPHIE_H

#include <vector>
#include <string>
#include "Reference.h"
#include "ContratException.h"

/*
 * \namespace biblio
 * \brief namespace pour la construction de bibliographie
 */


namespace biblio
{

  class Bibliographie
  {
  public:
    Bibliographie (const std::string& p_nomBibliographie);
    Bibliographie (const Bibliographie& p_bibliographie);
    ~Bibliographie ();

    Bibliographie& operator= (const Bibliographie& p_bibliographie);
    const std::string reqNomBibliographie () const;
    void ajouterReference (const biblio::Reference& p_nouvelleReference);
    const std::string reqBibliographieFormate () const;
    void supprimerReference (const std::string& p_identifiant);

  private:
    bool referenceEstDejaPresente (const Reference& p_reference) const;
    void copierVecteur (const Bibliographie& p_bibliographie);
    void viderVecteur ();
    void verifieInvariant () const;

    std::string m_nomBibliographie;
    std::vector<biblio::Reference*> m_vReferences;

  };
} // namespace biblio

#endif /* BIBLIOGRAPHIE_H */


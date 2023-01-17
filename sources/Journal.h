/*
 * \file Journal.h
 * \brief initialisation de la classe Journal
 * \author Emilio Lemus
 * \date 2022-11-28
 */

#ifndef JOURNAL_H
#define JOURNAL_H

#include <string>
#include "Reference.h"
#include "ContratException.h"

/*
 * \namespace biblio
 * \brief namespace pour la construction de bibliographie
 */

namespace biblio
{

  class Journal : public biblio::Reference
  {
  public:
    Journal (const std::string& p_auteurs, const std::string& p_titre,
             const unsigned int& p_annee, const std::string& p_identifiant,
             const std::string& p_nom, const unsigned int& p_volume,
             const unsigned int& p_numero, const unsigned int& p_page);

    const std::string reqNom () const;
    int reqVolume () const;
    int reqNumero () const;
    int reqPage () const;

    virtual const std::string reqReferenceFormate () const;
    virtual Reference* clone () const;


  private:
    void verifieInvariant () const;

    std::string m_nom; // nom de la revue
    int m_volume; // volume de la revue
    int m_numero; // numero de la revue
    int m_page; // page ou la reference ce situe
  };
} // namespace biblio

#endif /* JOURNAL_H */


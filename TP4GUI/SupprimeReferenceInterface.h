/*
 * \file SupprimerReferenceInterface.h
 * \brief Interface de la classe supprimerreference
 * \author Equipe 14
 * \date 2022-11-28
 *
 */

#ifndef _SUPPRIMEREFERENCEINTERFACE_H
#define _SUPPRIMEREFERENCEINTERFACE_H

#include "ui_SupprimeReferenceInterface.h"

/*
 * \brief Classe SupprimeReferenceInterface
 */
class SupprimeReferenceInterface : public QDialog
{
  Q_OBJECT
public:
  SupprimeReferenceInterface ();
  virtual ~SupprimeReferenceInterface ();
  std::string reqIdentifiant () const;
  bool entreeSontValide () const;

private slots:
  void valideEnregistrement ();


private:
  Ui::SupprimeReferenceInterface widget;

};

#endif /* _SUPPRIMEREFERENCEINTERFACE_H */

﻿#include "ShapeDialog.h"

ShapeDialog::ShapeDialog(wxWindow* parent) : wxDialog(parent, wxID_ANY, "Choose Shape", wxDefaultPosition, wxSize(300, 300)) {
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

        wxArrayString shapeChoices;
        shapeChoices.Add("Line");
        shapeChoices.Add("Polyline");
        shapeChoices.Add("Curve");
        shapeChoices.Add("Circle");
        shapeChoices.Add("Ellipse");
        shapeChoices.Add("Square");
        shapeChoices.Add("Triangle");

        shapeChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, shapeChoices);
        shapeChoice->SetSelection(0);
        mainSizer->Add(shapeChoice, 0, wxALL | wxEXPAND, 5);

        wxStaticText* colorLabel = new wxStaticText(this, wxID_ANY, "Choose Color:");
        mainSizer->Add(colorLabel, 0, wxALL, 5);

        colorPicker = new wxColourPickerCtrl(this, wxID_ANY);
        mainSizer->Add(colorPicker, 0, wxALL | wxEXPAND, 5);

        fillCheckBox = new wxCheckBox(this, wxID_ANY, "Fill Shape");
        mainSizer->Add(fillCheckBox, 0, wxALL, 5);

        wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
        wxButton* okButton = new wxButton(this, wxID_OK, "OK");
        wxButton* cancelButton = new wxButton(this, wxID_CANCEL, "Cancel");
        buttonSizer->Add(okButton, 1, wxALL | wxEXPAND, 5);
        buttonSizer->Add(cancelButton, 1, wxALL | wxEXPAND, 5);

        mainSizer->Add(buttonSizer, 0, wxALL | wxEXPAND, 5);

        SetSizerAndFit(mainSizer);
}

wxString ShapeDialog::GetSelectedShape() const {
    return shapeChoice->GetString(shapeChoice->GetSelection());
}

wxColour ShapeDialog::GetSelectedColor() const {
    return colorPicker->GetColour();
}

bool ShapeDialog::IsFilled() const {
    return fillCheckBox->IsChecked();
}
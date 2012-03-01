function jiscpmrisk_organization_risks(_organization_select, _risk_select_id, _with_all_option, _all_text) {
  var risk_select = $("#" + _risk_select_id).get(0);
  jiscpm_empty_select(risk_select);
  var organization_nid = _organization_select.value;
  if (!organization_nid) organization_nid=0;

  $.ajax({
    type: "GET",
    async: true,
    url: Drupal.settings.jiscpm.organization_risks_url + Drupal.encodeURIComponent(organization_nid),
    dataType: "string",
    success: function (data) {
      var items = Drupal.parseJson(data);
      jiscpm_fill_select(risk_select, items, _with_all_option, _all_text);
    }
  });
};

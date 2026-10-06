
        function atualizarTela(valor) {
            document.getElementById("valor").value = valor.toFixed(2);

            document.getElementById("valorExibido").textContent =
                "R$ " + valor.toFixed(2).replace(".", ",");
        }

        function atualizarValorManual() {
            const campo = document.getElementById("valorManual");

            const valor = parseFloat(campo.value || 0);

            atualizarTela(valor);
        }

        function adicionarValor(valor) {
            const campo = document.getElementById("valorManual");

            const valorAtual = parseFloat(campo.value || 0);

            const novoValor = valorAtual + valor;

            campo.value = novoValor.toFixed(2);

            atualizarTela(novoValor);
        }


        function validarDoacao() {
            const valor = document.getElementById("valorManual").value;
            const pagamento = document.querySelector('input[name="opcao"]:checked');

            if (!valor || parseFloat(valor) <= 0) {
                alert("Por favor, insira um valor válido para a doação.");
                return false;
            }

            if (!pagamento) {
                alert("Por favor, selecione uma forma de pagamento.");
                return false;
            }


            return true;
        }
